class Werknemer:
    def __init__(self, werknemer_id, voornaam, achternaam, credits):
        self.werknemer_id = werknemer_id
        self.voornaam = voornaam
        self.achternaam = achternaam
        self.credits = credits
        self.current_bestelling = None
        self.overige_credits = 0
        print("Werknemer is gecreëerd")

    def assign_bestelling(self, bestelling):
        self.current_bestelling = bestelling
        self.overige_credits = bestelling.credits
        print(f"Werknemer {self.werknemer_id} krijgt bestelling {bestelling.bestelling_id} van {bestelling.credits} credits")