/**
This file (c) by : - Martin Hammerchmidt alias Imote
This file is licensed under a
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
You should have received a copy of the license along with this
work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
If you have contributed to this file, add your name to authors list.
*/

#include <QApplication>
#include <QPixmap>
#include "screenmanager.h"

//This module is used by Uplimg to capture screen by different ways.

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ScreenTaker * capture = ScreenTaker::get();

    QObject::connect(capture, &ScreenTaker::captureSelectedZoneFinished, [](QPixmap picture)
    {
       picture.save("/home/imote/selectedArea.png");
    });
    capture->captureSelectedZone(QColor(255,0,0)); //Will ask the user to select area from his screen. When it's done, signal is emitted like showed just before

    QPixmap picture = capture->captureFullScreen(); //Will capture all screen and return the picture
    picture.save("/home/imote/fullscreen.png");

    return app.exec();
}
