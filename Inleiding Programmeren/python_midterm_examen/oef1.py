def nieuwe_datum(maand, jaar, maanden):
    # Bereken de totale maanden door de huidige maand op te tellen bij het aantal maanden.
    totale_maanden = maand + maanden

    # Bereken het nieuwe jaar en maand.
    nieuw_jaar = jaar + (totale_maanden - 1) // 12
    nieuwe_maand = (totale_maanden - 1) % 12 + 1

    # Retourneer de nieuwe datum als een string.
    return f"{nieuwe_maand}-{nieuw_jaar}"


print(nieuwe_datum(1, 2024, 5))
print(nieuwe_datum(11, 2023, 3))
print(nieuwe_datum(1, 2022, 11))
print(nieuwe_datum(6, 2021, 19))
print(nieuwe_datum(3, 2020, 24))
print(nieuwe_datum(10, 2019, 5))
print(nieuwe_datum(2, 2025, 10))
print(nieuwe_datum(8, 2030, 15))
print(nieuwe_datum(5, 2026, 36))
print(nieuwe_datum(9, 2018, 50))
print(nieuwe_datum(12, 2027, 600))