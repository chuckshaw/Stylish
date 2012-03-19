#include "widgetviewer.h"

WidgetViewer::WidgetViewer(QWidget *parent) :
    QWidget(parent)
{
    this->setLayout(new QGridLayout(this));
    this->setContentsMargins(10, 10, 10, 10);

    //QPushButton
    _enabledPushButton = new QPushButton("Label", this);
    _enabledPushButton->setObjectName("ENABLED_QPUSHBUTTON");
    layout()->addWidget(new QLabel("Enabled QPushButton:"));
    layout()->addWidget(_enabledPushButton);

    _disabledPushButton = new QPushButton("Label", this);
    _disabledPushButton->setObjectName("DISABLED_QPUSHBUTTON");
    _disabledPushButton->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QPushButton:"));
    layout()->addWidget(_disabledPushButton);

    //QToolButton
    _enabledToolButton = new QToolButton(this);
    _enabledToolButton->setObjectName("ENABLED_QTOOLBUTTON");
    layout()->addWidget(new QLabel("Enabled QToolButton:"));
    layout()->addWidget(_enabledToolButton);

    _disabledToolButton = new QToolButton(this);
    _disabledToolButton->setObjectName("DISABLED_QTOOLBUTTON");
    _disabledToolButton->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QToolButton:"));
    layout()->addWidget(_disabledToolButton);

    //QRadioButton
    _enabledRadioButton = new QRadioButton(this);
    _enabledRadioButton->setObjectName("ENABLED_QRADIOBUTTON");
    layout()->addWidget(new QLabel("Enabled QRadioButton:"));
    layout()->addWidget(_enabledRadioButton);

    _disabledRadioButton = new QRadioButton(this);
    _disabledRadioButton->setObjectName("DISABLED_QRADIOBUTTON");
    _disabledRadioButton->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QRadioButton:"));
    layout()->addWidget(_disabledRadioButton);

    //QCheckBox
    _enabledCheckBox = new QCheckBox(this);
    _enabledCheckBox->setObjectName("ENABLED_QCHECKBOX");
    layout()->addWidget(new QLabel("Enabled QCheckBox:"));
    layout()->addWidget(_enabledCheckBox);

    _disabledCheckBox = new QCheckBox(this);
    _disabledCheckBox->setObjectName("DISABLED_QCHECKBOX");
    _disabledCheckBox->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QCheckBox:"));
    layout()->addWidget(_disabledCheckBox);

    //QComboBox
    _enabledComboBox = new QComboBox(this);
    _enabledComboBox->setObjectName("ENABLED_QCOMBOBOX");
    layout()->addWidget(new QLabel("Enabled QComboBox:"));
    layout()->addWidget(_enabledComboBox);

    _disabledComboBox = new QComboBox(this);
    _disabledComboBox->setObjectName("DISABLED_QCOMBOBOX");
    _disabledComboBox->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QComboBox:"));
    layout()->addWidget(_disabledComboBox);

    //QSpinBox
    _enabledSpinBox = new QSpinBox(this);
    _enabledSpinBox->setObjectName("ENABLED_QSPINBOX");
    layout()->addWidget(new QLabel("Enabled QSpinBox:"));
    layout()->addWidget(_enabledSpinBox);

    _disabledSpinBox = new QSpinBox(this);
    _disabledSpinBox->setObjectName("DISABLED_QSPINBOX");
    _disabledSpinBox->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QSpinBox:"));
    layout()->addWidget(_disabledSpinBox);

    //QDoubleSpinBox
    _enabledDoubleSpinBox = new QDoubleSpinBox(this);
    _enabledDoubleSpinBox->setObjectName("ENABLED_QDOUBLESPINBOX");
    layout()->addWidget(new QLabel("Enabled QDoubleSpinBox:"));
    layout()->addWidget(_enabledDoubleSpinBox);

    _disabledDoubleSpinBox = new QDoubleSpinBox(this);
    _disabledDoubleSpinBox->setObjectName("DISABLED_QDOUBLESPINBOX");
    _disabledDoubleSpinBox->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QDoubleSpinBox:"));
    layout()->addWidget(_disabledDoubleSpinBox);

    //QLineEdit
    _enabledLineEdit = new QLineEdit(this);
    _enabledLineEdit->setObjectName("ENABLED_QLINEEDIT");
    layout()->addWidget(new QLabel("Enabled QLineEdit:"));
    layout()->addWidget(_enabledLineEdit);

    _disabledLineEdit = new QLineEdit(this);
    _disabledLineEdit->setObjectName("DISABLED_QLINEEDIT");
    _disabledLineEdit->setEnabled(false);
    layout()->addWidget(new QLabel("Disabled QLineEdit:"));
    layout()->addWidget(_disabledLineEdit);

    //QTextEdit
    //QTimeEdit
    //QDateEdit
    //QDateTimeEdit
    //QSlider
    //QDial
    //QScrollbar

}
