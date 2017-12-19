import proio.proto as proto

import google.protobuf.descriptor_pool as descriptor_pool
import google.protobuf.message_factory as message_factory

class Event:
    """Class representing a single event"""

    def __init__(self, proto_obj = None):
        self._proto = proto_obj or proto.Event()
        self._entry_cache = {}
        self._factory = message_factory.MessageFactory()
        self._rev_type_lookup = {}

    def add_entry(self, tag, entry):
        type_id = self._get_type_id(entry)

        self._proto.nEntries += 1
        ID = self._proto.nEntries
        self._proto.entries[ID].type = type_id

        self._entry_cache[ID] = entry

        self.tag_entry(ID, tag)

        return ID

    def add_entries(self, tag, *entries):
        ids = []
        for entry in entries:
            ids.append(self.add_entry(tag, entry))
        return ids

    def get_entry(self, ID):
        try:
            return self._entry_cache[ID]
        except KeyError:
            pass

        try:
            entry_proto = self._proto.entries[ID]
        except KeyError:
            return

        type_string = self._proto.types[entry_proto.type]
        type_desc = descriptor_pool.Default().FindMessageTypeByName(type_string)
        msg_class = self._factory.GetPrototype(type_desc)
        entry = msg_class.FromString(entry_proto.payload)
        self._entry_cache[ID] = entry

        return entry

    def tag_entry(self, ID, tag):
        try:
            tag_proto = self._proto.tags[tag]
        except KeyError:
            tag_proto = proto.Tag()
            self._proto.tags[tag] = tag_proto

        tag_proto.entries.append(ID)

    def tags(self):
        tags = []
        for tag in self._proto.tags.keys():
            tags.append(tag)
        tags.sort()
        return tags

    def tagged_entries(self, tag):
        return self._proto.tags[tag].entries

    def _get_type_id(self, entry):
        type_name = entry.DESCRIPTOR.full_name
        try:
            return self._rev_type_lookup[type_name]
        except KeyError:
            for ID, name in self._proto.types.items():
                if name == type_name:
                    self._rev_type_lookup[name] = ID
                    return ID

            self._proto.nTypes += 1
            type_id = self._proto.nTypes
            self._proto.types[type_id] = type_name
            self._rev_type_lookup[type_name] = type_id

            return type_id

    def _flush_cache(self):
        for ID, entry in self._entry_cache.items():
            self._proto.entries[ID].payload = entry.SerializeToString()
        self._entry_cache = {}

    def __str__(self):
        print_string = ''

        tags = self.tags()
        for tag in tags:
            print_string += 'Tag: ' + tag + '\n'
            entries = self.tagged_entries(tag)
            for entry_id in entries:
                print_string += 'ID:%i ' % entry_id
                entry = self.get_entry(entry_id)
                if entry != None:
                    print_string += '%s\n' % entry
                else:
                    print_string += 'not found'

        return print_string
