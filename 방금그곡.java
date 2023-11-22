import java.util.ArrayList;
import java.util.List;

public class 방금그곡 {
	public static String solution59(String m, String[] musicinfos) {

		//"ABCDEFG"
		// ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]

		m = sharp(m);

		String answer = "(None)";
		int longestPlayTime = 0;

		String[] music;
		int playTime;
		String fullsong;

		for (String flow : musicinfos) {
			music = flow.split(",");
			playTime = playTime(music[0], music[1]);
			fullsong = fullSong(music[3], playTime);

			if (fullsong.contains(m) && playTime > longestPlayTime) {
				longestPlayTime = playTime;
				answer = music[2];
			}
		}

		return answer;
	}

	public static int playTime(String a, String b) {
		String[] songStrat = a.split(":");
		String[] songEnd = b.split(":");

		return (Integer.parseInt(songEnd[0]) * 60 + Integer.parseInt(songEnd[1]))
				- (Integer.parseInt(songStrat[0]) * 60 + Integer.parseInt(songStrat[1]));
	}

	public static String fullSong (String music, int playTime) {
		StringBuilder fullsong = new StringBuilder();
		char[] musicArray = music.toCharArray();

		int j = 0;
		for (int i = 0; i < playTime; i++) {
			fullsong.append(musicArray[j]);
			j++;
			if (j >= musicArray.length)
				j = 0;
		}

		return fullsong.toString();
	}

	public static String sharp(String music) {
		music = music.replaceAll("C#", "c");
		music = music.replaceAll("D#", "d");
		music = music.replaceAll("F#", "f");
		music = music.replaceAll("G#", "g");
		music = music.replaceAll("A#", "a");
		return music;
	}
}
