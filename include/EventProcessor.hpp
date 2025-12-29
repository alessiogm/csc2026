#pragma once

#include <vector>

namespace csc2026 {

struct Particle {
    double px{};
    double py{};
    double pz{};
    double mass{};

    double energy() const;
};

struct Event {
    int id{};
    std::vector<Particle> particles{};
};

class EventProcessor {
public:
    EventProcessor() = default;

    void reset();

    void processEvent(const Event& event);
    void processEvents(const std::vector<Event>& events);

    int totalTracks() const { return m_totalTracks; }
    double totalEnergy() const { return m_totalEnergy; }

    static std::vector<Event> generateSampleEvents(size_t nEvents);

private:
    int m_totalTracks{0};
    double m_totalEnergy{0.0};
};

} // namespace csc2026

