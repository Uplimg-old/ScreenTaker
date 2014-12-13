/**
This file (c) by : - Martin Hammerchmidt alias Imote
This file is licensed under a
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
You should have received a copy of the license along with this
work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
If you have contributed to this file, add your name to authors list.
*/

#ifndef AREAUSERDEFINER_H
#define AREAUSERDEFINER_H

#include <QObject>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QRect>
#include <QSize>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRubberBand>
#include <QMouseEvent>
#include <QColor>
#include <QPalette>

class AreaUserDefiner : public QLabel
{
    Q_OBJECT
public:
    AreaUserDefiner(QColor areaColor);
    virtual ~AreaUserDefiner();

protected:
    QRubberBand * rubberBand;
    QPoint origin;

    virtual void mousePressEvent(QMouseEvent * e);
    virtual void mouseMoveEvent(QMouseEvent * e);
    virtual void mouseReleaseEvent(QMouseEvent * e);
    virtual void keyPressEvent(QKeyEvent * e);

signals:
    void areaTaken(QRect);
    void areaCanceled();

public slots:
    void start();
};

#endif // AREAUSERDEFINER_H
