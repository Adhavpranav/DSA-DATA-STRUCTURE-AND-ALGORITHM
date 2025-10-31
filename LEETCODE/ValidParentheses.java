public class Validpara {
    public boolean isValid(String s) {
        ArrayDeque<Character> obj = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                obj.push(s.charAt(i));
            } else {
                if (obj.isEmpty())
                    return false;
                char top = obj.pop();
                if ((s.charAt(i) == ')' && top != '(') ||
                        (s.charAt(i) == '}' && top != '{') ||
                        (s.charAt(i) == ']' && top != '['))
                    return false;
            }
        }
        return obj.isEmpty();
    }
}
