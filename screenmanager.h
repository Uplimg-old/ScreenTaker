/**
This file (c) by : - Martin Hammerchmidt alias Imote
This file is licensed under a
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
You should have received a copy of the license along with this
work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
If you have contributed to this file, add your name to authors list.
*/

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QGuiApplication>
#include <QPixmap>
#include <QScreen>

#include "areauserdefiner.h"

class ScreenTaker : public QObject
{
    Q_OBJECT
public:
    static ScreenTaker * get(QObject * parent = 0) //Use this function to get the instance. This is needed because only one instance of ScreenTaker can be called.
    {
        static ScreenTaker * s;
        if(!s) s = new ScreenTaker(parent);
        return s;
    }

    QPixmap captureFullScreen();
    bool captureSelectedZone(QColor areaColor);
    //QPixmap captureSpecificWindow(); -> not implemented yet

private:
    explicit ScreenTaker(QObject * parent = 0); //Constructor is private, use get(QObject * parent = 0) instead

signals:
    void captureSelectedZoneFinished(QPixmap);
    void captureSelectedZoneCanceled();

public slots:
};

#endif // SCREENMANAGER_H
