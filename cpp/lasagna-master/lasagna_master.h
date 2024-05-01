#pragma once

#include <string>
#include <vector>

namespace lasagna_master {
    const std::string NOODLE_LAYER = "noodles";
    const std::string SAUCE_LAYER = "sauce";
    const int NOODLES_PER_LAYER = 50;
    const double SAUCE_PER_LAYER = 0.2;

    struct amount {
        int noodles;
        double sauce;
    };

    int preparationTime(std::vector<std::string> layers, int prep_time_per_layer);
    int preparationTime(std::vector<std::string> layers);

    amount quantities(std::vector<std::string> layers);

    void addSecretIngredient(std::vector<std::string>& my_list, const std::vector<std::string> friend_list);
    void addSecretIngredient(std::vector<std::string>& my_list, const std::string secretIngredient);

    std::vector<double> scaleRecipe(const std::vector<double> quantities, int portions);
}
