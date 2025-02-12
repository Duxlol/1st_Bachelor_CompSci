class Bestelling:
    def __init__(self,bestelling_id , gebruikersid, timestamp, credits):
        self.bestelling_id = bestelling_id
        self.gebruikersid = gebruikersid
        self.timestamp = timestamp
        self.credits = credits
        self.status = False

    def maakBestelling(self):
        """"
        maakt een bestelling aan met gegeven variabelen
        pre: id, gebruikersid, timestamp, chocolademelk-id en status
        post: maakt een bestelling aan
        """
        pass

    def veranderStatus(self, bestelling):
        """
        verander de status van de bestelling
        pre: de gegeven bestelling
        post: status van nt-afgehaald naar afgehaald
        """
        pass
