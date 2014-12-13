/**
This file (c) by : - Martin Hammerchmidt alias Imote
This file is licensed under a
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
You should have received a copy of the license along with this
work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
If you have contributed to this file, add your name to authors list.
*/

#include "screenmanager.h"

ScreenTaker::ScreenTaker(QObject *parent) : QObject(parent){}

QPixmap ScreenTaker::captureFullScreen()
{
    QScreen * screen = QGuiApplication::primaryScreen();
    if(!screen) return QPixmap();
    return screen->grabWindow(0);
}

/* Windows, Mac and Linux don't work the same way FIXME: only linux implemented at the moment*/
bool ScreenTaker::captureSelectedZone(QColor areaColor)
{
    QScreen * screen = QApplication::primaryScreen();
    if(!screen) return false;

    QPixmap capture = screen->grabWindow(0);
    if(capture.isNull()) return false;

    AreaUserDefiner * area = new AreaUserDefiner(areaColor);
    area->setPixmap(capture);

    QObject::connect(area, &AreaUserDefiner::areaTaken, [capture, area, this](QRect areaSelected)
        {
            QPixmap finalCapture = capture.copy(areaSelected);
            emit captureSelectedZoneFinished(finalCapture);
            area->deleteLater();
        });

    QObject::connect(area, &AreaUserDefiner::areaCanceled, this, &ScreenTaker::captureSelectedZoneCanceled);
    QObject::connect(area, &AreaUserDefiner::areaCanceled, area, &AreaUserDefiner::deleteLater);

    area->start();

    return true;
}

