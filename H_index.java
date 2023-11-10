public class H_index {

	public int solution(int[] citations) {
		int answer = 0;
		int hIndex;
		int citationsLength = citations.length;

		for (int i = 1; i <= citationsLength; i++) {
			hIndex = 0;

			for (int j : citations)
				if (j >= i)	hIndex++;

			if (hIndex >= i) answer = i;
		}

		return answer;
	}

}
