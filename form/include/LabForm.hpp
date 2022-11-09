#pragma once

#include "ui_form.h"
#include <cstddef>
#include <cstdint>
#include <qlineedit.h>
#include <string>

#include "hash.hpp"

class LabForm : public QMainWindow {

  Q_OBJECT

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
  const std::uint64_t hash_key{45678};
  const std::uint64_t index_count{1000};
  const std::uint64_t hash_digits{3};
};