from files import *

#(a) Lees het gegeven bestand input.txt in met de correcte encoding.
content = read_file('input.txt', en='utf-8')

#(b) Schrijf de inhoud van de file weg naar een bestand, en maak daarbij gebruik van de UTF-16 encoding. Noem dit bestand text_in_UTF_16.txt
write_file('text_in_UTF_16.txt', content, en='utf-16')

#(c) Zet alle karakters om naar hun overeenkomstige code points. Sla deze op in een bestand genaamd code_points.txt.
#voor elk karakter in originele txt, omzetten nr unicode door U+XXXX, aanvullen met 0'en
code_points_content = ' '.join(f"U+{ord(char):04X}" for char in content)
write_file('code_points.txt', code_points_content, en='utf-8')

#(d) Zet de tekst om naar HTML code entities en sla dit op in 'text_in_HTML.html'
def conv_to_html(txt):
    result=""
    for char in txt:
        if char == '\n':
            result += '<br>'  # een enter in html als het een newline character is
        else:
            result += f'&#x{ord(char):X};'  # converteer naar html codes in hexadecimaal
    return result
html = conv_to_html(content)
write_html_file('text_in_HTML.html',html)

