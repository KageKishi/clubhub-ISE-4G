// include/clubhub/queued_checkin.hpp
#pragma once
#include <chrono>
#include <optional>
#include <string>
#include <vector>

namespace clubhub {
`
enum class SyncState { Pending, Sent, Accepted, Rejected };

// One check-in recorded on an organiser's phone while offline.
struct QueuedCheckIn {
    std::string localId;    // TODO: why a UUID made on the device?
    std::string deviceId;
    std::string eventId;
    std::string studentId;
    std::chrono::sys_seconds scannedAt;   // device clock: trust it?
    // TODO: attempts, state, the server's reject reason (optional)
};

class CheckInQueue {
public:
    // false if this student is already queued for this event
    bool enqueue(QueuedCheckIn item);
    // oldest first; what the next sync attempt uploads
    std::vector<QueuedCheckIn> pending() const;
    void markAccepted(const std::string& localId);
    void markRejected(const std::string& localId, std::string reason);

private:
    std::vector<QueuedCheckIn> items_;
};

} // namespace clubhub