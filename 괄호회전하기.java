import java.util.Stack;

public class 괄호회전하기 {
	// 괄호 회전하기
	public int solution63(String s) {
		int answer = 0;

		for (int i = 0; i < s.length(); i++) {
			if (rolling(s, i))
				answer++;
		}

		return answer;
	}

	public boolean rolling (String s, int i) {
		Stack<Character> stack = new Stack<Character>();

		String tmpLeft = s.substring(0, i + 1);
		String tmpRight = s.substring(i + 1, s.length());

		char[] tmpArray = (tmpRight + tmpLeft).toCharArray();

		for (char c : tmpArray) {
			if (c == '(' || c == '{' || c == '[')
				stack.push(c);
			else if (c == ')' && !stack.isEmpty() && stack.peek() == '(')
				stack.pop();
			else if (c == '}' && !stack.isEmpty() && stack.peek() == '{')
				stack.pop();
			else if (c == ']' && !stack.isEmpty() && stack.peek() == '[')
				stack.pop();
			else
				return false;
		}

		return stack.empty();
	}
}
