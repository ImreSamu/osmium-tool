/*

Osmium -- OpenStreetMap data manipulation command line tool
http://osmcode.org/osmium

Copyright (C) 2013-2017  Jochen Topf <jochen@topf.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <sstream>

#include <osmium/io/file.hpp>

#include "extract.hpp"

void Extract::open_file(const osmium::io::Header& header, osmium::io::overwrite output_overwrite, osmium::io::fsync sync) {
    osmium::io::File file{m_output, m_output_format};
    m_writer.reset(new osmium::io::Writer{file, header, output_overwrite, sync});
}

void Extract::close_file() {
    if (m_writer) {
        m_writer->close();
    }
}

void Extract::write(const osmium::memory::Item& item) {
    (*m_writer)(item);
}

std::string Extract::envelope_as_text() const {
    std::stringstream ss;
    ss << m_envelope;
    return ss.str();
}
