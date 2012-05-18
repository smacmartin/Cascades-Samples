/* Copyright (c) 2012 Research In Motion Limited.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "cowbellapp.h"

#include <bb/cascades/Page>
#include <bb/cascades/QmlDocument>

using namespace bb::cascades;

CowBellApp::CowBellApp()
{
    // Here we create a QMLDocument and load it, we are using build patterns.
    QmlDocument *qml = QmlDocument::create().load("cowbell.qml");

    if (!qml->hasErrors()) {

        // The application Page is created from QML.
        Page *appPage = qml->createRootNode<Page>();

        if (appPage) {

            // Setting the context property we want to use from inside the QML. functions exposed
            // via Q_INVOKABLE will be found with the property and the name of the function.
            qml->setContextProperty("cowbellApp", this);

            //Sound manager, we initialize the sound manager with a directory that resides in the
            //assets directory and that directory only contains playable files.
            mSoundManager = new SoundManager("sounds/");

            // Finally the main scene for the application is set the Page.
            Application::setScene(appPage);
        }

    }
}

CowBellApp::~CowBellApp()
{
    // Destroy the sound manager.
    if (mSoundManager)
    	delete mSoundManager;
}

void CowBellApp::playSound(const QString &msg)
{
    if (mSoundManager)
    	mSoundManager->play(msg);
}

