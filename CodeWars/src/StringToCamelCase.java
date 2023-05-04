

public class StringToCamelCase {

    public static void main(String[] args) {
        System.out.println(StringToCamelCase.convert("vito0000_==r"));
    }

    public static String convert(String s) {
        StringBuilder sg = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isAlphabetic(c))
                sg.append(Character.toUpperCase(c));
        }
        return sg.toString();
    }

}

