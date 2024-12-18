/**
 * Copyright [2024] <wangdc1111@gmail.com>
 * for a coding test.
 */
#ifndef INC_INTENSITY_SEGMENTS_HPP_
#define INC_INTENSITY_SEGMENTS_HPP_

#include <map>

class IntensitySegments {
 public:
    IntensitySegments() = default;
    ~IntensitySegments() = default;

    IntensitySegments(const IntensitySegments&) = default;
    IntensitySegments& operator=(const IntensitySegments&) = default;
    IntensitySegments(IntensitySegments&&) = default;
    IntensitySegments& operator=(IntensitySegments&&) = default;

    /**
     * @brief public interface to do the adding operation on intensity segments.
     * @param from The inclusive start value of the segement.
     * @param to The exclusive end value of the segment.
     * @param amount The amount of the intensity to be used.
     */
    void add(int from, int to, int amount) {
        updateSegments(from, to, amount, false);
    }

    /**
     * @brief public interface to do the setting operation on intensity segments.
     * @param from The inclusive start value of the segement.
     * @param to The exclusive end value of the segment.
     * @param amount The amount of the intensity to be used.
     */
    void set(int from, int to, int amount) {
        updateSegments(from, to, amount);
    }

    /**
     * @brief public interface to print the content of current intesity segements infomation to stdout.
     */
    void toString(void);

 private:
    /**
     * @brief private method actually excecuting the setting operation.
     * @param from The inclusive start value of the segement.
     * @param to The exclusive end value of the segment.
     * @param amount The amount of the intensity to be used.
     * @param bSet The flag to control container operation mode (add or set), set by default.
     */
    void updateSegments(int from, int to, int amount, bool bSet = true);

    /**
     * @brief the container to hold the value pairs of segment to intensity 
     */
    std::map<int, int> segments;
};

#endif  // INC_INTENSITY_SEGMENTS_HPP_
