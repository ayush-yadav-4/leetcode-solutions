class Solution {
    public static final long LIMIT = 1_000_000_000_000l; // keep start/end smaller than 10^12
    
public String abbreviateProduct(int left, int right) {
    long end = 1; // end part of the product (or the whole number if small enough)
    long nZeros = 0; // trailing zeros
    boolean usedModulo = false;
    for (int n = left; n <= right; n++) {
        end *= n;

        while (end % 10 == 0) { // extract trailing zeros into nZeros
            end /= 10;
            nZeros++;
        }

        if (end >= LIMIT) { // truncate if needed
            end %= LIMIT;
            usedModulo = true;
        }
    }

    if (!usedModulo && end < 10_000_000_000l) { // doesn't need abbreviation below 10^10
        return String.format("%de%d", end, nZeros);
    }

    double start = 1; // start part of the product
    for (int n = left; n <= right; n++) {
        start *= n;

        while (start >= LIMIT) { // truncate if needed
            start /= 10;
        }
    }

    return buildAbbreviation(usedModulo, start, end, nZeros);
}

private String buildAbbreviation(boolean usedModulo, double start, long end, long nZeros) {
    while (start >= 100_000) { // keep the 5 first digits
        start /= 10;
    }

    end %= 100_000; // keep the last 5 digits

    return String.format("%d...%05de%d", (int) start, end, nZeros); // zero-padding of the end
}
}