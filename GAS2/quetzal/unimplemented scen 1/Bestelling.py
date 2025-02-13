class Bestelling:
    def __init__(self,bestelling_id , gebruikersid, timestamp, credits):
        """
        initialiseren van een bestelling
        pre: bestelling_id, gebruikersid, timestamp, credits
        post: bestelling object met status 'niet afgehaald'
        """
        self.bestelling_id = bestelling_id
        self.gebruikersid = gebruikersid
        self.timestamp = timestamp
        self.credits = credits
        self.status = False

    def maakBestelling(self):
        """"
        maak een bestelling aan met gegven vars
        pre: id, gebruikersid, timestamp, chocolademelk-id, status
        post: maak een bestelling
        """
        pass

    def veranderStatus(self, bestelling):
        """
        verander de status van de bestelling
        pre: de gegeven bestelling
        post: status van nt-afgehaald naar afgehaald
        """
        pass