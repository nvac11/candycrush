#pragma once
#include <utility>

class CursorSelection {
private:
    std::pair<int, int> c1; // Stores grid position (row, col)
    std::pair<int, int> c2; // Stores grid position (row, col)

public:
    bool isc1clicked;
    bool isc2clicked;

    CursorSelection() : c1(-1, -1), c2(-1, -1), isc1clicked(false), isc2clicked(false) {}

    void setc1(int row, int col) {
        c1.first = row;
        c1.second = col;
        isc1clicked = true;
    }

    void setc2(int row, int col) {
        c2.first = row;
        c2.second = col;
        isc2clicked = true;
    }

    void resetSelection() {
        isc1clicked = false;
        isc2clicked = false;
    }

    std::pair<std::pair<int, int>, std::pair<int, int>> getScreenPosition() const {
        return {c1, c2};
    }

    void handleSquareClick(int row, int col) {
        if (!isc1clicked) {
            setc1(row, col);
        } else if (!isc2clicked) {
            setc2(row, col);
        } else {
            resetSelection();
        }
    }
};
