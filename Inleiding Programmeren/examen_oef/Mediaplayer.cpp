#include "Mediaplayer.h"
#include <iostream>
#include <string>
#include "Time.h"

Mediaplayer::Mediaplayer() {};
Mediaplayer::~Mediaplayer() {};
void Mediaplayer::add_audiobestand(Audiobestand *a) {
  if (a == nullptr) {
    std::cout << "Error: Ongeldig audiobestand." << std::endl;
    return;
  }
  bestanden.push_back(a);
};

void Mediaplayer::toon_huidig_audiobestand() const {
  if (!is_playing) {
    std::cout << "Geen nummer wordt momenteel afgespeeld." << std::endl;
    return;
  }

  if (huidige_playlist.empty()) {
    std::cout << "Geen playlist geladen." << std::endl;
    return;
  }

  const auto& playlist = playlists.at(huidige_playlist);
  if (playlist.empty()) {
    std::cout << "De huidige playlist is leeg." << std::endl;
    return;
  }

  // Get the currently playing track
  const Audiobestand* currentTrack = playlist[current_index];
  std::cout << currentTrack->getTitel() << " - " << currentTrack->getUitvoerder()
            << " - " << Time(currentTrack->getDuur()).toString() << std::endl;
}


void Mediaplayer::make_playlist(const std::string& playlistnaam) {
  if (playlists.find(playlistnaam) != playlists.end()) {
    std::cout << "Error: Playlist " << playlistnaam << " bestaat al." << std::endl;
    return;
  }

  playlists[playlistnaam] = std::vector<Audiobestand*>();
};

void Mediaplayer::add_to_playlist(const std::string& playlistnaam, const std::string& bestand) {
  if (playlists.find(playlistnaam) == playlists.end()) {
    std::cout << "Error: Playlist " << playlistnaam << " niet gevonden." << std::endl;
    return;
  }

  // find audio file
  Audiobestand* file = nullptr;
  for (Audiobestand* a: bestanden) {
    if (a->getTitel() == bestand) {
      file = a;
      break;
    }
  }
  if (file == nullptr) {
    std::cout << "Error: Audiobestand '" << bestand << " niet gevonden in de bibliotheek." << std::endl;
    return;
  }

  // add to playlist
  playlists[playlistnaam].push_back(file);

};

void Mediaplayer::laad_playlist(const std::string& playlistnaam) {
  if (playlists.find(playlistnaam) == playlists.end()) {
    std::cout << "Error: Playlist '" << playlistnaam << "' niet gevonden" << std::endl;
    return;
  }

  // zet playlist naar huidige
  huidige_playlist = playlistnaam;
  current_index = 0;

  const vector<Audiobestand*>& playlist = playlists.at(playlistnaam);

  // totale duur van playlist
  int totaleTijd = 0;
  for (Audiobestand* audiobestand : playlist) {
    totaleTijd += audiobestand->getDuur();
  }

  // omzetten tijd
  Time tijd(totaleTijd);

  cout << "Playlist geladen: " << playlistnaam << " - " << tijd.toString() << endl;
};

void Mediaplayer::toon_huidige_playlist() const {
  if (huidige_playlist.empty()) {
    std::cout << "Geen playlist geladen." << std::endl;
    return;
  }

  const vector<Audiobestand*>& playlist = playlists.at(huidige_playlist);

  long totaleTijd = 0;
  for (const Audiobestand* audiobestand : playlist) {
    totaleTijd += audiobestand->getDuur();
  }
  Time tijd(totaleTijd);
  cout << huidige_playlist << " - " << tijd.toString() << endl;

  // display tracks
  for (size_t index = 0; index < playlist.size(); ++index) {
    if (index == current_index && is_playing) {
      std::cout << "> " << playlist[index]->getTitel() << std::endl;
    } else {
      std::cout << "- " << playlist[index]->getTitel() << std::endl;
    }
  }
};

void Mediaplayer::speel_volgende() {
  if (huidige_playlist.empty()) {
    std::cout << "Geen playlist geladen." << std::endl;
    return;
  }

  const auto& playlist = playlists.at(huidige_playlist);
  if (playlist.empty()) {
    std::cout << "De huidige playlist is leeg." << std::endl;
    return;
  }
  if (!is_playing) {
    is_playing = true;
    current_index = 0;  // Start from the first song
  } else {
    current_index = (current_index + 1) % playlist.size();  // Move to the next track
  }
  playlist[current_index]->speelAf();  // Play the current track

};