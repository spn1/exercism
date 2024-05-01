#include <iostream>
#include "lasagna_master.h"

namespace lasagna_master {
    int preparationTime(
        std::vector<std::string> layers,
        int prep_time_in_minutes
    ) {
        return layers.size() * prep_time_in_minutes;
    };

    int preparationTime(
        std::vector<std::string> layers
    ) {
        return layers.size() * 2;
    }

    amount quantities(std::vector<std::string> layers) {
        amount measurements {};
        int noodle_count {0};
        int sauce_count {0};

        for (std::string layer : layers) {
            if (layer == NOODLE_LAYER) {
                noodle_count += 1;
                continue;
            } else if (layer == SAUCE_LAYER) {
                sauce_count += 1;
                continue;
            }
        }

        measurements.noodles = noodle_count * NOODLES_PER_LAYER;
        measurements.sauce = sauce_count * SAUCE_PER_LAYER;

        return measurements;
    }

    void addSecretIngredient(std::vector<std::string>& my_list, const std::vector<std::string> friend_list) {
        std::string secret_ingredient = friend_list.back();
        my_list.pop_back();
        my_list.push_back(secret_ingredient);
    }

    void addSecretIngredient(std::vector<std::string>& my_list, const std::string secretIngredient) {
        my_list.pop_back();
        my_list.push_back(secretIngredient);
    }

    std::vector<double> scaleRecipe(const std::vector<double> quantities, int portions) {
        std::vector<double> scaled_quantities {};

        for (double quantity : quantities) {
            scaled_quantities.push_back(quantity * (portions / 2.0));
        };

        return scaled_quantities;
    }
}
