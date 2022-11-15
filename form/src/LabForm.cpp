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
  typename counter_t::batch_count_t batches = ui->batchCount->value();
  m_score_counter.calc_score(batches);

  set_text(ui->divHash, m_score_counter.score().division);
  set_text(ui->squareHash, m_score_counter.score().midsquare);
  set_text(ui->wrapHash, m_score_counter.score().wrapping);
  set_text(ui->multHash, m_score_counter.score().multiplication);
}