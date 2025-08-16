class Solution {
    public boolean isRobotBounded(String instructions) {
        // Directions: N, E, S, W
        int[][] dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int x = 0, y = 0, dir = 0; // start at (0,0) facing North (dir=0)

        for (char c : instructions.toCharArray()) {
            if (c == 'G') {
                x += dirs[dir][0];
                y += dirs[dir][1];
            } else if (c == 'L') {
                dir = (dir + 3) % 4; // left turn
            } else if (c == 'R') {
                dir = (dir + 1) % 4; // right turn
            }
        }

        // Robot is bounded if back at origin OR not facing North
        return (x == 0 && y == 0) || dir != 0;
    }
}
