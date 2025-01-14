def scores(vakken):
    """
    Berekent de gemiddelde en hoogste scores per vak.

    Parameters:
    data (dict): Een dictionary waarin de sleutels vaknamen zijn en de waarden
                 dictionaries met studentennamen en hun scores.

    Returns:
    dict: Een dictionary waarin de sleutels vaknamen zijn en de waarden tuples
          bevatten van de gemiddelde score en de hoogste score.
    """
    resultaten = {}

    for vak, student_scores in vakken.items():
        scores = list(student_scores.values())
        gemiddelde = sum(scores) / len(scores)
        hoogste = max(scores)
        resultaten[vak] = (gemiddelde, hoogste)

    return resultaten

vakken = {
    "wiskunde": {"Alice": 83, "Bob": 91, "Cindy": 67},
    "geschiedenis": {"Alice": 76, "Bob": 89, "Cindy": 94, "David": 61},
    "natuurkunde": {"Alice": 88, "Bob": 73},
    "biologie": {"Alice": 54, "Cindy": 85, "David": 79},
    "scheikunde": {"Alice": 93, "Bob": 65, "David": 84},
    "aardrijkskunde": {"Cindy": 71, "David": 60},
    "informatica": {"Alice": 90, "Bob": 79, "Cindy": 87, "David": 82},
    "economie": {"Bob": 69, "Cindy": 72},
    "filosofie": {"Alice": 85, "Bob": 74, "Cindy": 91},
    "Engels": {"Alice": 78, "David": 66},
    "Nederlands": {"Alice": 82, "Bob": 77, "Cindy": 80, "David": 75},
}
print(scores(vakken))