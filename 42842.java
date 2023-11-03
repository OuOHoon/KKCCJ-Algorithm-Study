public static int[] solution(int brown, int yellow) {

		int maxX = (brown / 2) - 2;
		int x = (brown / 2) - 3;

		// brown/2 - 2 = x * y
		// x * y = yellow
		// x-- = yellow - 1
		// 가로가 세로보다 항상 길다.

		for (int y = 1; y < maxX; y++) {
			if ((x * y) == yellow)
				return new int[]{x + 2,y + 2};
			x--;
		}
		return null;
	}