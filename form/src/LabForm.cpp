#include "LabForm.hpp"


LabForm::LabForm(QWidget *parent) : QMainWindow(parent), ui{new Ui::LabForm} {
  ui->setupUi(this);
  ui->retranslateUi(this);

  configure_slots();
}

LabForm::~LabForm() { delete ui; }

void LabForm::configure_slots() {
  connect(ui->quitBtn, SIGNAL(clicked()), this, SLOT(close()));
}