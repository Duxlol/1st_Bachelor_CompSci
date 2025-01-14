#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include "Audiobestand.h"
#include <vector>
#include <string>
#include <map>

class Mediaplayer {
public:
  Mediaplayer();
  ~Mediaplayer();
  void add_audiobestand(Audiobestand *a);
  void toon_huidig_audiobestand() const;
  void make_playlist(const std::string& naam);
  void add_to_playlist(const std::string& playlistnaam, const std::string& bestand);
  void laad_playlist(const std::string& playlistnaam);
  void toon_huidige_playlist() const;
  void speel_volgende();

private:
  std::vector<Audiobestand*> bestanden;
  std::map<std::string, std::vector<Audiobestand*>> playlists;
  std::string huidige_playlist;
  int current_index;
  bool is_playing = false;
};



#endif //MEDIAPLAYER_H
