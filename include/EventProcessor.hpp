// CSC Latin America 2026 - Event Processor
#pragma once

#include "Particle.hpp"
#include <vector>
#include <string>

namespace csc2026 {

struct Event {
    int eventNumber = 0;
    std::vector<Particle> particles;
    
    // Reconstruct tracks (placeholder for exercises)
    std::vector<Particle> reconstructTracks() const { return particles; }
};

class EventProcessor {
public:
    EventProcessor() = default;
    
    // Process a single event
    void processEvent(const Event& event);
    
    // Process multiple events (can be parallelized)
    void processEvents(const std::vector<Event>& events);
    
    // Get results
    int totalTracksProcessed() const { return m_totalTracks; }
    double totalEnergy() const { return m_totalEnergy; }
    
    // Reset counters
    void reset();
    
private:
    int m_totalTracks = 0;
    double m_totalEnergy = 0.0;
};

// Generate sample events for testing
std::vector<Event> generateSampleEvents(int nEvents, int particlesPerEvent = 10);

} // namespace csc2026
