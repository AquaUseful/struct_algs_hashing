#pragma once

#include <cstddef>
#include <cstdint>
#include <qlineedit.h>
#include <string>

#include "Counter.hpp"
#include "hash.hpp"
#include "ui_form.h"

class LabForm : public QMainWindow {

  Q_OBJECT

public:
  using counter_t = Counter;

public:
  explicit LabForm(QWidget *parent = nullptr);
  virtual ~LabForm();

private:
  void configure_slots();
  void update_division_hash();
  void update_multiplication_hash();
  void update_square_center_hash();
  void update_wrapping_hash();

  template <typename T> void set_text(QLineEdit *line, T value) {
    const auto str = std::to_string(value);
    line->setText(QString::fromStdString(str));
  }

private slots:
  void update_hashes();

private:
  Ui::LabForm *ui;
  counter_t m_score_counter;
};