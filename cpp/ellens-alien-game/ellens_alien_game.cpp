#include <iostream>

namespace targets {
  class Alien {
    public:
      int x_coordinate {};
      int y_coordinate {};

      Alien(int x, int y) {
        x_coordinate = x;
        y_coordinate = y;
      }

      int get_health() {
        return health;
      }

      bool hit() {
        std::cout << health;
        if (health > 0) {
          health -= 1;
        }
        return true;
      }

      bool is_alive() {
        std::cout << health;
        return health <= 0;
      }

      bool teleport(int new_x, int new_y) {
        x_coordinate = new_x;
        y_coordinate = new_y;
        return true;
      }

      bool collision_detection(Alien alien) {
         return alien.x_coordinate == x_coordinate && alien.y_coordinate == y_coordinate;
      }
    private:
      int health {3};
  };
};
