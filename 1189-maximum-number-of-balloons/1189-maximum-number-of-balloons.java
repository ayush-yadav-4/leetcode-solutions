class Solution {
    public int maxNumberOfBalloons(String text) {
        Map<Character, Integer> mp = new HashMap<>();

        for (char c : text.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        int b = mp.getOrDefault('b', 0);
        int a = mp.getOrDefault('a', 0);
        int l = mp.getOrDefault('l', 0) / 2;
        int o = mp.getOrDefault('o', 0) / 2;
        int n = mp.getOrDefault('n', 0);

        return Math.min(b, Math.min(a, Math.min(l, Math.min(o, n))));
    }
}
