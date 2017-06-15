#pragma once

#include <experimental/optional>
#include <vector>

enum class Sign {
    Zero, Positive, Negative
};

struct IntegerConstraint {
    std::experimental::optional<int> min;
    std::experimental::optional<int> max;
    std::experimental::optional<Sign> sign;
    std::experimental::optional<bool> is_even;

    IntegerConstraint();
};

struct ListConstraint {
    std::experimental::optional<int> min_length;
    std::experimental::optional<int> max_length;
    std::experimental::optional<int> min;
    std::experimental::optional<int> max;
    std::vector<std::experimental::optional<Sign>> sign;
    std::vector<std::experimental::optional<bool>> is_even;

    ListConstraint();
    IntegerConstraint generate_integer_constraint() const;
    std::vector<IntegerConstraint> all_constraints() const;
};

std::experimental::optional<int> generate_integer(const IntegerConstraint& constraint);
std::experimental::optional<std::vector<int>> generate_list(const ListConstraint &constraint);

