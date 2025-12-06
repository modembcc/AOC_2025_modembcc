import java.io.File;                  // Import the File class
import java.io.FileNotFoundException; // Import this class to handle errors
import java.util.Scanner;             // Import the Scanner class to read text files

public class two {
    public static void main(String[] args) {
    File myObj = new File("two.in");
    try (Scanner myReader = new Scanner(myObj)) {
        while (myReader.hasNextLine()) {
            String data = myReader.nextLine();
            String[] intervals = data.split(",");
            long ans = 0;
            for (String interval : intervals) {
                String[] arr = interval.split("-");
                long start = Long.parseLong(arr[0]);
                long end = Long.parseLong(arr[1]);
                ans += solve(start, end);
            }
            System.out.println(ans);
        }
    } catch (FileNotFoundException e) {
        System.out.println("An error occurred.");
        e.printStackTrace();
    }
    }

    static long solve(long start, long end) {
        long ans = 0;
        for (long i = start; i <= end; i++) {
            String tmp = Long.toString(i);
            boolean invalid = true;
            int len = tmp.length();
            for (int j  = 1; j <= len / 2; j++) {
                boolean found = true;
                if (len % j != 0) continue;
                String mold = tmp.substring(0, j);
                for (int bi = j; bi < len; bi += j) {
                    if (mold.compareTo(tmp.substring(bi, bi + j)) != 0) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    invalid = false;
                }
            }
            if (!invalid) ans+=i;
        }
        return ans;
    }
}