# get_next_line
My diarrhea inducing get_next_line for 42born2code.

- Doesn't use libft 🙂
- Handles multiple fd's but doesn't free their associated read buffer when it's empty, which would have been better.
- Handles a '\0' in the file as far as the subject allows it (would be better if get_next_line could return the length of the line)
- Questionnably complies to 42born2code's norm (Actually it doesn't but norminette doesn't detect it)
- Reallocates the line buffer by adding BUF_SIZE bytes each time, which is bad for very long lines (even with a BUFF_SIZE of 4096 for a ~1MB line, complexity is O^2).
- Obscure naming of most identifiers.
- ft_printf.c is 42 lines long.
- Features comments!
