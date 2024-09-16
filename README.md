# Rock Paper Scissors
#### Version 1.0

This is a Qt application that aims to prevent me from forgetting how to code while enjoying student life. It uses CPP instead of QML because I learnt Qt with PySide and the syntax between CPP and Python is similar.

## Featured Features
- Qrc file to compile images into the application
- Ui file for aided UI design
- Android compiling
- Qt Creator aided design (if this wasn't obvious enough)

## Installation
The app is available on Linux desktops and Android from the Releases page. Simply install it and run it.

### Compiling from source
I have puposefully left out some files so it cannot be compiled out of the box because I know you really want to run it on Windows and I want to try and learn how to cross-compile. It will come, eventually, hopefully, maybe?

## Future Plans
I will add things if I want, unless you decided to hire me and demand that I have to add things.

## How to Contribute
Don't, this project is simply a fun solo project. Where's the fun if you tell me I need to add an AndroidManifest.xml myself created by clicking create template in Projects > Build > Build Android APK > Android Customization > Create Templates then add a line `QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android` to cmake which was demonstrated in the documentation in an obscure page instead of the page called Qt Android Manifest File Configuration.
It's not like I spent days changing keywords in my Google search where I finally found a project which recommended copying the manifest in the build file then I was able to find the page from searching how to sign my apk file after the fact that the manifest file was copied from the build folder. 
Sometimes you ask yourself why internet people don't read the documentation, ask Google why [Android Deploy Configuration](https://doc.qt.io/qtcreator/creator-deploying-android.html#editing-manifest-files) (The actual link to create the template) is next to [Deploying an Application on Android](https://doc.qt.io/Qt-5/deployment-android.html) and on that page it links to manifest creation but not how to do it on Qt.
Then get second hand scolding from nerds that provide wrong solutions and get blamed for simply being dumb and should have referred it while giving a page to the documentation that does not mention which part of the documentation is related to the issue like seriously if you don't know the solution to a problem just shut up. Did you know the massive threads that solve my "elementary problems" is really unecessessarily long becuase **THERE ISN'T CLEAR DOCUMENTATION ON THE TOPIC**.
Have I mentioned the `QT_ANDROID_PACKAGE...` line was never mentioned anywhere in the documentation immediately available after a Google search.

Special thanks to [Tomz](https://forum.qt.io/user/tomz) for his kind words on different forums, this project could have been another forgotten unfinished project if not for his detailed back and forth conversations with other forum members to troubleshoot issues until the very end. (Seriously, he pops up in a lot of different pages)
