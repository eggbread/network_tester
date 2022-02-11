/** @file
 *    @brief MAVLink comm protocol testsuite generated from bioair.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef BIOAIR_TESTSUITE_H
#define BIOAIR_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_bioair(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_bioair(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"
#include "../ardupilotmega/testsuite.h"


static void mavlink_test_bioair_configurations(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bioair_configurations_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,963498712,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,197,8,75,142,209
    };
    mavlink_bioair_configurations_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.origin_north = packet_in.origin_north;
        packet1.origin_east = packet_in.origin_east;
        packet1.origin_down = packet_in.origin_down;
        packet1.dest_north = packet_in.dest_north;
        packet1.dest_east = packet_in.dest_east;
        packet1.dest_down = packet_in.dest_down;
        packet1.min_relative_alt = packet_in.min_relative_alt;
        packet1.sig_high = packet_in.sig_high;
        packet1.sig_low = packet_in.sig_low;
        packet1.sig_gamma = packet_in.sig_gamma;
        packet1.sig_alpha = packet_in.sig_alpha;
        packet1.sig_beta = packet_in.sig_beta;
        packet1.virtual_a = packet_in.virtual_a;
        packet1.repulsor = packet_in.repulsor;
        packet1.target_proximity = packet_in.target_proximity;
        packet1.target_force = packet_in.target_force;
        packet1.node_id = packet_in.node_id;
        packet1.origin_id = packet_in.origin_id;
        packet1.dest_id = packet_in.dest_id;
        packet1.node_state = packet_in.node_state;
        packet1.tentacle_state = packet_in.tentacle_state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_configurations_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bioair_configurations_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_configurations_pack(system_id, component_id, &msg , packet1.node_id , packet1.origin_id , packet1.dest_id , packet1.node_state , packet1.tentacle_state , packet1.origin_north , packet1.origin_east , packet1.origin_down , packet1.dest_north , packet1.dest_east , packet1.dest_down , packet1.min_relative_alt , packet1.sig_high , packet1.sig_low , packet1.sig_gamma , packet1.sig_alpha , packet1.sig_beta , packet1.virtual_a , packet1.repulsor , packet1.target_proximity , packet1.target_force );
    mavlink_msg_bioair_configurations_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_configurations_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.node_id , packet1.origin_id , packet1.dest_id , packet1.node_state , packet1.tentacle_state , packet1.origin_north , packet1.origin_east , packet1.origin_down , packet1.dest_north , packet1.dest_east , packet1.dest_down , packet1.min_relative_alt , packet1.sig_high , packet1.sig_low , packet1.sig_gamma , packet1.sig_alpha , packet1.sig_beta , packet1.virtual_a , packet1.repulsor , packet1.target_proximity , packet1.target_force );
    mavlink_msg_bioair_configurations_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bioair_configurations_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_configurations_send(MAVLINK_COMM_1 , packet1.node_id , packet1.origin_id , packet1.dest_id , packet1.node_state , packet1.tentacle_state , packet1.origin_north , packet1.origin_east , packet1.origin_down , packet1.dest_north , packet1.dest_east , packet1.dest_down , packet1.min_relative_alt , packet1.sig_high , packet1.sig_low , packet1.sig_gamma , packet1.sig_alpha , packet1.sig_beta , packet1.virtual_a , packet1.repulsor , packet1.target_proximity , packet1.target_force );
    mavlink_msg_bioair_configurations_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_bioair_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BIOAIR_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bioair_status_t packet_in = {
        17235,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131 }
    };
    mavlink_bioair_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.message_type = packet_in.message_type;
        
        mav_array_memcpy(packet1.payload, packet_in.payload, sizeof(uint8_t)*249);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bioair_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_status_pack(system_id, component_id, &msg , packet1.message_type , packet1.payload );
    mavlink_msg_bioair_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.message_type , packet1.payload );
    mavlink_msg_bioair_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bioair_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_status_send(MAVLINK_COMM_1 , packet1.message_type , packet1.payload );
    mavlink_msg_bioair_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_bioair_velocity_command(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bioair_velocity_command_t packet_in = {
        17.0,45.0,73.0,41,108,175
    };
    mavlink_bioair_velocity_command_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.vn = packet_in.vn;
        packet1.ve = packet_in.ve;
        packet1.vd = packet_in.vd;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.node_id = packet_in.node_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_velocity_command_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bioair_velocity_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_velocity_command_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.node_id , packet1.vn , packet1.ve , packet1.vd );
    mavlink_msg_bioair_velocity_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_velocity_command_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.node_id , packet1.vn , packet1.ve , packet1.vd );
    mavlink_msg_bioair_velocity_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bioair_velocity_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bioair_velocity_command_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.node_id , packet1.vn , packet1.ve , packet1.vd );
    mavlink_msg_bioair_velocity_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_bioair(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_bioair_configurations(system_id, component_id, last_msg);
    mavlink_test_bioair_status(system_id, component_id, last_msg);
    mavlink_test_bioair_velocity_command(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BIOAIR_TESTSUITE_H
