# ft_printf

%[flag][min width][precision][length modifier][conversion specifier]

% -> flags (#, 0, -, +, ' ') -> minw (* || 1-9) -> precision (. && (* || 1-9)) -> length (hh, h, l, ll) -> conversions (cspdiouxXf%)

conversions:
%i : integar (base 10)
%d : decimal (integar) number (base 10)
%s : string of characters
%p : pointer address
%f : floating-point number
%o : octal bumber (base 8)
%u : unsigned decimal (integar) number
%x %X : number in hexadecimal (base 16)
%% : print a precent sign

flags:
'-' : creates a left justifying printf output
'0' : integar zero-fill, left-pads the number with zeros instead of spaces
'+' : means when used it will print a plus sign before the output
'#' : Used with the specifiers the value is precceeded with 0, 0x or 0X for values different than 0
' ': If no sign is going to be written, a blank space is inserted before the value.

s
flags: - : left align
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: if it is zero or less it is ignored, if it's bigger than the string it's ignored
2nd flags: ignore all

c
flags: - : left align
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: ignored
2nd flags: l : 'wint_t'

p
flags: - : left align
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: ignored
2nd flags: ignored

d/i - signed decimal/integer
flags: Prepended +, - and ' ' count towards the min width
'-' : left-align
'+' : prepends '+' or '-'
' ' : prepends ' ' or '-'
- IGNORED: when flag '+' is present
'0' : fills width with 0's, if there is a plus or minus sign it comes before the zeros
CHECK: width option, prepended vals before 0's
- IGNORED: when flag '-' is present
- CHECK!!! if precision is present only fills zeros to the limit of precision
so if num is 6 chars and precision is 7 and min width is 10 it will add 1 0 and 3 empty spaces
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: if precision is smaller than the length of the number it is ignored, but if it is bigger it is filled with 0's
2nd flags: ll : long long, l : long, hh: char, h : short

u - unsigned int
flags: Prepended +, - and ' ' count towards the min width
'-' : left-align
'0' : fills width with 0's, if there is a plus or minus sign it comes before the zeros
CHECK: width option, prepended vals before 0's
- IGNORED: when flag '-' is present
- CHECK!!! if precision is present only fills zeros to the limit of precision
so if num is 6 chars and precision is 7 and min width is 10 it will add 1 0 and 3 empty spaces
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: if precision is smaller than the length of the number it is ignored, but if it is bigger it is filled with 0's
2nd flags: ll : long long, l : long, hh: char, h : short

o - unsigned int
flags: Prepended +, - and ' ' count towards the min width
'-' : left-align
'0' : fills width with 0's, if there is a plus or minus sign it comes before the zeros
CHECK: width option, prepended vals before 0's
- IGNORED: when flag '-' is present
- CHECK!!! if precision is present only fills zeros to the limit of precision
so if num is 6 chars and precision is 7 and min width is 10 it will add 1 0 and 3 empty spaces
'#' : 0 is prepended to non-zero numbers.
CHECK: val is not zero
IMPORTANT: 0 counts towards min-width, but not precision and is prepended
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: if precision is smaller than the length of the number it is ignored, but if it is bigger it is filled with 0's
2nd flags: ll : long long, l : long, hh: char, h : short

x - unsigned int
flags: Prepended +, - and ' ' count towards the min width
'-' : left-align
'0' : fills width with 0's, if there is a plus or minus sign it comes before the zeros
CHECK: width option, prepended vals before 0's
- IGNORED: when flag '-' is present
- CHECK!!! if precision is present only fills zeros to the limit of precision
so if num is 6 chars and precision is 7 and min width is 10 it will add 1 0 and 3 empty spaces
'#' : 0x is prepended to non-zero numbers.
CHECK: val is not zero
IMPORTANT: 0x counts towards min-width, but not precision and is prepended
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: if precision is smaller than the length of the number it is ignored, but if it is bigger it is filled with 0's
2nd flags: ll : long long, l : long, hh: char, h : short

X - unsigned int
flags: Prepended +, - and ' ' count towards the min width
'-' : left-align
'0' : fills width with 0's, if there is a plus or minus sign it comes before the zeros
CHECK: width option, prepended vals before 0's
- IGNORED: when flag '-' is present
- CHECK!!! if precision is present only fills zeros to the limit of precision
so if num is 6 chars and precision is 7 and min width is 10 it will add 1 0 and 3 empty spaces
'#' : 0x is prepended to non-zero numbers.
CHECK: val is not zero
IMPORTANT: 0X counts towards min-width, but not precision and is prepended
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: if precision is smaller than the length of the number it is ignored, but if it is bigger it is filled with 0's
2nd flags: ll : long long, l : long, hh: char, h : short

f - double

always 6 decimal places unless otherwise specified and a 0 is added before the decimal if it is less than 1 flags: Prepended +, - and ' ' count towards the min width '-' : left-align '+' : prepends '+' or '-' ' ' : prepends ' ' or '-' - IGNORED: when flag '+' is present '0' : fills width with 0's, if there is a plus or minus sign it comes before the zeros CHECK: width option, prepended vals before 0's - IGNORED: when flag '-' is present min-width: is the total width, if width is smaller than min width, its filled with empty spaces precision: refers to number of decimal places, precision of zero has a decimal and nothing after it 2nd flags: L : long double, l : long
% -
flags:
'-' : left-align
'0' : fills width with 0's
CHECK: width option, prepended vals before 0's
- IGNORED: when flag '-' is present
- CHECK!!! if precision is present only fills zeros to the limit of precision
so if num is 6 chars and precision is 7 and min width is 10 it will add 1 0 and 3 empty spaces
min-width: is the total width, if width is smaller than min width, its filled with empty spaces
precision: ignore
