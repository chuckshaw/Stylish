#ifndef WIDGETVIEWER_H
#define WIDGETVIEWER_H

#include <QWidget>
#include <QtGui>

class WidgetViewer : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetViewer(QWidget *parent = 0);

signals:

public slots:


private:
    QPushButton* _enabledPushButton;
    QPushButton* _disabledPushButton;
    QToolButton* _enabledToolButton;
    QToolButton* _disabledToolButton;
    QRadioButton* _enabledRadioButton;
    QRadioButton* _disabledRadioButton;
    QCheckBox* _enabledCheckBox;
    QCheckBox* _disabledCheckBox;
    QComboBox* _enabledComboBox;
    QComboBox* _disabledComboBox;
    QSpinBox* _enabledSpinBox;
    QSpinBox* _disabledSpinBox;
    QDoubleSpinBox* _enabledDoubleSpinBox;
    QDoubleSpinBox* _disabledDoubleSpinBox;
    QLineEdit* _enabledLineEdit;
    QLineEdit* _disabledLineEdit;
    QTextEdit* _enabledTextEdit;
    QTextEdit* _disabledTextEdit;
    QTimeEdit* _enabledTimeEdit;
    QTimeEdit* _disabledTimeEdit;
    QDateEdit* _enabledDateEdit;
    QDateEdit* _disabledDateEdit;
    QDateTimeEdit* _enabledDateTimeEdit;
    QDateTimeEdit* _disabledDateTimeEdit;
    QSlider* _enabledSlider;
    QSlider* _disabledSlider;
    QDial* _enabledDial;
    QDial* _disabledDial;
    QScrollBar* _enabledScrollBar;
    QScrollBar* _disabledScrollBar;

};

#endif // WIDGETVIEWER_H
