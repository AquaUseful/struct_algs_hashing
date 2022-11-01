#pragma once

#include "ui_form.h"
#include <cstddef>
#include <cstdint>

#include "hash.hpp"

class LabForm : public QMainWindow {

  Q_OBJECT

public:
  explicit LabForm(QWidget* parent = nullptr);
  virtual ~LabForm();

private:
  void configure_slots();
  void update_division_hash();

private slots:
  void update_hashes();

private:
  Ui::LabForm* ui;
  const std::size_t hash_key {45678};
  const std::size_t index_count {1000};
};