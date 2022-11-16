#include "LabForm.hpp"
#include "Bench.hpp"
#include "hash_multiplication.hpp"
#include "hash_square_center.hpp"
#include "hash_wrapping.hpp"

#include <cmath>
#include <string>

LabForm::LabForm(QWidget *parent)
    : QMainWindow(parent), ui{new Ui::LabForm}, m_benchmark(10'000, 10'000) {
  ui->setupUi(this);
  ui->retranslateUi(this);

  m_benchmark.refill();

  configure_slots();
}

LabForm::~LabForm() { delete ui; }

void LabForm::configure_slots() {
  connect(ui->quitBtn, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->calculateBtn, SIGNAL(clicked()), this,
          SLOT(update_collision_score()));
  connect(ui->updateArraysBtn, SIGNAL(clicked()), this, SLOT(update_arrays()));
  connect(ui->compareBtn, SIGNAL(clicked()), this, SLOT(update_search_bench()));
}

void LabForm::update_collision_score() {
  typename counter_t::batch_count_t batches = ui->batchCount->value();
  m_score_counter.calc_score(batches);

  set_text(ui->divHash, m_score_counter.score().division);
  set_text(ui->squareHash, m_score_counter.score().midsquare);
  set_text(ui->wrapHash, m_score_counter.score().wrapping);
  set_text(ui->multHash, m_score_counter.score().multiplication);
}

void LabForm::update_search_bench() {
  const auto oa_result = m_benchmark.oa_bench();
  set_text(ui->openTime, oa_result.time.count());
  set_text(ui->openCmp, oa_result.comparisons);
  set_text(ui->openFound, oa_result.found_count);
}

void LabForm::update_arrays() { m_benchmark.refill(); }