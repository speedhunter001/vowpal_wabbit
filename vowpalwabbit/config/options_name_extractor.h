// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#pragma once

#include <set>
#include <string>

#include "config/options.h"
#include "future_compat.h"
#include "io/logger.h"

namespace VW
{
namespace config
{
struct options_name_extractor : options_i
{
  std::string generated_name;
  std::set<std::string> m_added_help_group_names;
  std::set<std::string> m_unused;

  void internal_add_and_parse(const option_group_definition& group) override;
  VW_ATTR(nodiscard) bool was_supplied(const std::string&) const override;
  VW_ATTR(nodiscard) const std::set<std::string>& get_supplied_options() const override;
  void check_unregistered(VW::io::logger& /* logger */) override;
  void insert(const std::string&, const std::string&) override;
  void replace(const std::string&, const std::string&) override;
  VW_ATTR(nodiscard) std::vector<std::string> get_positional_tokens() const override;
};

}  // namespace config
}  // namespace VW
