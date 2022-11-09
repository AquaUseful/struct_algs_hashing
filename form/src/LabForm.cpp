#include "LabForm.hpp"
#include "hash_multiplication.hpp"
#include "hash_square_center.hpp"
#include "hash_wrapping.hpp"

#include <cmath>
#include <string>

LabForm::LabForm(QWidget *parent) : QMainWindow(parent), ui{new Ui::LabForm} {
  ui->setupUi(this);
  ui->retranslateUi(this);

  configure_slots();
}

LabForm::~LabForm() { delete ui; }

void LabForm::configure_slots() {
  connect(ui->quitBtn, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->calculateBtn, SIGNAL(clicked()), this, SLOT(update_hashes()));
}

void LabForm::update_hashes() {
  update_division_hash();
  update_multiplication_hash();
  update_square_center_hash();
  update_wrapping_hash();
}

void LabForm::update_division_hash() {
  const auto hash = hash_division(hash_key, 997);
  set_text(ui->divHash, hash);
}

void LabForm::update_multiplication_hash() {
  const auto hash =
      hash_multiplication(hash_key, (std::sqrt(5) - 1) / 2, index_count);
  set_text(ui->multHash, hash);
}

void LabForm::update_square_center_hash() {
  const auto hash = hash_midsquare(hash_key, hash_digits);
  set_text(ui->squareHash, hash);
}

void LabForm::update_wrapping_hash() {
  const auto hash = hash_wrapping(hash_key, index_count);
  set_text(ui->wrapHash, hash);
}