class Werknemer:
    def __init__(self, werknemer_id, voornaam, achternaam, credits):
        """
        Initialiseren van een werknemer
        pre: werknemer_id, voornaam, achternaam, credits
        post: werknemer object met een workload van credits
        """
        self.werknemer_id = werknemer_id
        self.voornaam = voornaam
        self.achternaam = achternaam
        self.credits = credits
        self.current_bestelling = None
        self.overige_credits = 0

    def assign_bestelling(self, bestelling):
        """
        Ken een bestelling toe aan de werknemer.
        Pre: bestelling (Bestelling).
        Post: Werknemer heeft de bestelling in behandeling.
        """
        self.current_bestelling = bestelling
        self.overige_credits = bestelling.credits
        print(f"Werknemer {self.werknemer_id} krijgt bestelling {bestelling.bestelling_id} van {bestelling.credits} credits")