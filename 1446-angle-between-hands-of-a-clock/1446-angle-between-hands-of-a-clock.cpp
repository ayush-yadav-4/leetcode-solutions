class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_angle = 6.0 * minutes;
        double hour_angle = 30.0 * (hour % 12) + 0.5 * minutes;

        double angle = fabs(hour_angle - minute_angle);
        return min(angle, 360.0 - angle);
    }
};
