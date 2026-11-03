#pragma once

#include <chrono>
#include <optional>
#include <string>
#include <vector>

namespace clubhub
{

    enum class SyncState
    {
        Pending,
        Sent,
        Accepted,
        Rejected
    };

    // One check-in recorded on an organiser's phone while offline.
    struct QueuedCheckIn
    {
        std::string localId; // UUID generated on device (ensures idempotency)
        std::string deviceId;
        std::string eventId;
        std::string studentId;
        std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> scannedAt; // device clock timestamp
        int attempts = 0;
        SyncState state = SyncState::Pending;
        std::optional<std::string> rejectReason;
    };

    class CheckInQueue
    {
    public:
        // false if this student is already queued for this event
        bool enqueue(QueuedCheckIn item);
        // oldest first; what the next sync attempt uploads
        std::vector<QueuedCheckIn> pending() const;
        void markAccepted(const std::string &localId);
        void markRejected(const std::string &localId, std::string reason);

    private:
        std::vector<QueuedCheckIn> items_;
    };

} // namespace clubhub