public class s87946 {

	public int solution(int k, int[][] dungeons) {
		int answer = 0;
		int nowDepth;
		int stamina;

		for (int i = 0; i < dungeons.length; i++) {
			nowDepth = 0;
			stamina = k;
			nowDepth = findTheBestWay(k, dungeons, nowDepth);
			if ( answer < nowDepth + 1 )
				answer = nowDepth + 1;
		}
		return answer;
	}

	public int findTheBestWay(int stamina, int[][]dungeons, int nowDepth) {

		int maxDepth = 0;

		if (nowDepth >= dungeons.length)
			return 0;

		if (stamina >= dungeons[nowDepth][0]) {
			stamina -= dungeons[nowDepth][1];
			int depth = 1 + findTheBestWay(stamina, dungeons, nowDepth + 1);
			if (depth > maxDepth)
				maxDepth = depth;
		}
		return maxDepth;
	}
}
