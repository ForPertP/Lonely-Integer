import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'lonelyinteger' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY a as parameter.
     */


    public static int lonelyinteger(List<Integer> a) {
        int uniqueElement = 0;

        for (int num : a) {
            uniqueElement ^= num;
        }

        return uniqueElement;
    }


    public static int lonelyinteger2(List<Integer> a) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        for (int num : a) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            if (entry.getValue() == 1) {
                return entry.getKey();
            }
        }

        return -1;
    }
    

    public static int lonelyinteger3(List<Integer> a) {
        int n = a.size();

        Set<Integer> uniqueElements = new HashSet<>(a);
        int u = uniqueElements.size();

        if (n == 1) return a.get(0);
        if (u <= 1) return -1;

        int k = (n - 1) / (u - 1);

        int result = 0;

        for (int i = 0; i < 32; i++) {
            int bitSum = 0;

            for (int num : a) {
                if (((num >> i) & 1) == 1) {
                    bitSum++;
                }
            }

            if (bitSum % k != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }    
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> a = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.lonelyinteger(a);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
