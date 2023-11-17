import java.util.ArrayList;
import java.util.List;

public class 하노이의탑 {
	public static int[][] solution53(int n) {
		List<int[]> traceHanoi = new ArrayList<>();

		Hanoi(n,1, 2, 3, traceHanoi);

		return traceHanoi.toArray(new int[traceHanoi.size()][]);
	}

	public static void Hanoi(int n, int first, int second, int third, List<int[]> result) {
		if (n == 0)
			return;

		Hanoi(n - 1, first, third, second, result);
		System.out.print(first + " ");
		System.out.println(third);
		result.add(new int[]{first, third});
		Hanoi(n - 1, second, first, third, result);
	}
}
