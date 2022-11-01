#include "LabForm.hpp"

#include <string>

LabForm::LabForm(QWidget* parent) : QMainWindow(parent), ui {new Ui::LabForm} {
  ui->setupUi(this);
  ui->retranslateUi(this);

  configure_slots();
}

LabForm::~LabForm() {
  delete ui;
}

void LabForm::configure_slots() {
  connect(ui->quitBtn, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->calculateBtn, SIGNAL(clicked()), this, SLOT(update_hashes()));
}

void LabForm::update_hashes() {
  update_division_hash();
}

void LabForm::update_division_hash() {
  const auto hash = hash_division(hash_key, std::size_t(997));
  const auto hash_str = std::to_string(hash);
  ui->divHash->setText(QString::fromStdString(hash_str));
}